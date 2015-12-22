#include "CQuadTree.h"
#include "QuadObject.h"
#include "CFileUtil.h"

CQuadTree::CQuadTree()
{
	this->m_maxID = 0;
	this->m_nodeRoot = new CQuadNode();
	this->m_nodeRoot->SetID(1);
}


// Xay dung lai quadtree
//Kiem tra neu doi tuong nao da die thi xoa no khoi quatree
void CQuadTree::ReBuildQuadTree(std::vector<CQuadObject*>& listQuadObj)
{
	// Kiem tra danh sach cac doi tuong.
	if (!listQuadObj.empty())
	{
		int size = listQuadObj.size();
		CQuadObject* quadObj;
		for (int i = 0; i < size; i++)
		{
			quadObj = listQuadObj.at(i);
			if (quadObj)
			{
				// Neu doi tuong k con Alive, xoa doi tuong khoi node.
				if (!quadObj->GetGameObject()->IsAlive())
				{
					// Xoa khoi danh sach doi tuong cua node
					this->m_nodeRoot->DeleteObjectFromQuadNode(quadObj);
					// Xoa khoi danh sach doi tuong
					delete listQuadObj.at(i);
					listQuadObj.erase(listQuadObj.begin() + i);
				}
			}
		}
	}
}

void CQuadTree::ReBuildQuadTree(const std::string& filePath)
{
	//Thong tin co ban cua mot node
	int iDNode;
	float posX;
	float posY;
	float width;
	float height;

	//
	std::vector<std::string> result = CFileUtil::GetInstance()->LoadFromFile(filePath);
	int size = result.size();
	
	if (size > 0)
	{
	
		std::string line;
		std::vector<std::string> dataInfo;
		for (int i = 0; i < size; i++)
		{
			line = result.at(i);
			dataInfo = CFileUtil::GetInstance()->Split(line, '\t');
			std::vector<int>* listIDObject = new std::vector<int>();
			if (!dataInfo.empty())
			{
				int size = dataInfo.size();
				iDNode = std::atoi(dataInfo.at(0).c_str());
				posX = std::atof(dataInfo.at(1).c_str());
				posY = std::atof(dataInfo.at(2).c_str());
				width = std::atof(dataInfo.at(3).c_str());
				height = std::atof(dataInfo.at(4).c_str());
				if (size > 5)
				{
					for (int j = 5; j < size; j++)
					{
						
						listIDObject->push_back(std::atoi(dataInfo.at(j).c_str()));
					}
				}
				CQuadNode* node = new CQuadNode(iDNode, posX, posY, width, height);
				node->SetListObject(listIDObject);
				this->AddNode(node, this->m_nodeRoot);
			}
		}
	}
}

void CQuadTree::AddNode(CQuadNode*& node, CQuadNode*& nodeRoot)
{
	if (node->GetID() == nodeRoot->GetID())
	{
		//Update thong tin
		nodeRoot->SetPosX(node->GetPosX());
		nodeRoot->SetPosY(node->GetPosY());
		nodeRoot->SetWidth(node->GetWidth());
		nodeRoot->SetHeight(node->GetHeight());
		nodeRoot->SetListObject(node->GetListObject());
		return;
	}
	if (node->GetID() > nodeRoot->GetID() * 8)
	{
		if (!nodeRoot->GetNodeTL())
		{
			nodeRoot->GetNodeTL() = new CQuadNode();
			nodeRoot->GetNodeTL()->SetID(nodeRoot->GetID() * 8 + 1);
		}
		if (!nodeRoot->GetNodeTR())
		{
			nodeRoot->GetNodeTR() = new CQuadNode();
			nodeRoot->GetNodeTR()->SetID(nodeRoot->GetID() * 8 + 2);
		}
		if (!nodeRoot->GetNodeBL())
		{
			nodeRoot->GetNodeBL() = new CQuadNode();
			nodeRoot->GetNodeBL()->SetID(nodeRoot->GetID() * 8 + 3);
		}
		if (!nodeRoot->GetNodeBR())
		{
			nodeRoot->GetNodeBR() = new CQuadNode();
			nodeRoot->GetNodeBR()->SetID(nodeRoot->GetID() * 8 + 4);
		}
		this->AddNode(node, nodeRoot->GetNodeTL());
		this->AddNode(node, nodeRoot->GetNodeTR());
		this->AddNode(node, nodeRoot->GetNodeBL());
		this->AddNode(node, nodeRoot->GetNodeBR());
	}
	else if (node->GetID() / 8 == nodeRoot->GetID())
	{
		switch (node->GetID() % 8)
		{
		case 1:
		{
				  nodeRoot->SetNodeTL(node);
				  break;
		}
		case 2:
		{
				  nodeRoot->SetNodeTR(node);
				  break;
		}
		case 3:
		{
				  nodeRoot->SetNodeBL(node);
				  break;
		}
		case 4:
		{
				  nodeRoot->SetNodeBR(node);
				  break;
		}
		}
	}

}

// Lay danh sach doi tuong tren man hinh viewport
//Xen viewPort
void CQuadTree::GetListObjectOnScreen(RECT* viewBox, CQuadNode*& node, std::vector<int>& listIDObj)
{
	if (viewBox && node)
	{
		// Xen viewPort voi node.
		if (node->IntersectRectRS(viewBox, node->GetBound()))
		{
			if (node->GetNodeTL())
			{
				this->GetListObjectOnScreen(viewBox, node->GetNodeTL(), listIDObj);
				this->GetListObjectOnScreen(viewBox, node->GetNodeTR(), listIDObj);
				this->GetListObjectOnScreen(viewBox, node->GetNodeBL(), listIDObj);
				this->GetListObjectOnScreen(viewBox, node->GetNodeBR(), listIDObj);
			}
			// Neu node la node la'
			else
			{
				// Get danh sach doi tuong cua node.
				std::vector<int>* listItem = node->GetListObject();
				if (listItem)
				{
					int size = listItem->size();
					int id;
					for (int i = 0; i < size; i++)
					{
						id = listItem->at(i);
						// Kiem tra doi tuong da ton tai trong d/s doi tuong xen voi viewport hay chua.
						if (!this->Contains(id, listIDObj))
						{
							// Add danh sach doi tuong vao danh sach doi tuong tren man hinh.
							listIDObj.push_back(id);
						}
					}
				}
			}
		}
	}
}

// Kiem tra id doi tuong, ton tai trong danh sach xen voi viewport hay chua.
bool CQuadTree::Contains(int ID, const std::vector<int>& list)
{
	if (!list.empty())
	{
		int size = list.size();
		for (int i = 0; i < size; i++)
		{
			if (list.at(i) == ID)
			{
				return true;
			}
		}
	}
	return false;
}

//node: Node goc, co the node goc khong phai la root
CQuadNode*& CQuadTree::SearchNode(int iDNode, CQuadNode*& node)
{
	CQuadNode* result = nullptr;
	if (iDNode == node->GetID())
	{
		return node;
	}
	else
	{
		if (iDNode / 8 != node->GetID() / 8)
		{
			if (node->GetNodeTL() && !this->SearchNode(iDNode, node->GetNodeTL()) &&
				node->GetNodeTR() && !this->SearchNode(iDNode, node->GetNodeTR()) &&
				node->GetNodeBL() && !this->SearchNode(iDNode, node->GetNodeBL()) &&
				node->GetNodeBR())
			{

				this->SearchNode(iDNode, node->GetNodeBR());
			}
		}
	}
	return result;
}

void CQuadTree::Clear()
{
	this->m_nodeRoot->Clear();
}

void CQuadTree::BuildQuadTree()
{

}

void CQuadTree::AddGameObjectToQuadTree(CBaseGameObject*& gameObj)
{
	CQuadObject* quadObj = new CQuadObject(++this->m_maxID, gameObj);
	if (this->m_nodeRoot && gameObj)
	{
		this->m_nodeRoot->ClipObject(quadObj);
	}
}

void CQuadTree::AddGameObjectToQuadTree(CQuadObject* quadObj)
{
	this->m_nodeRoot->ClipObject(quadObj);
}

void CQuadTree::DeleteGameObjectFromQuadTree(CQuadObject* quadObj)
{
	if (this->m_nodeRoot)
	{
		this->m_nodeRoot->DeleteObjectFromQuadNode(quadObj);
	}
}

CQuadTree::~CQuadTree()
{
	this->m_nodeRoot->~CQuadNode();
}