//
//  FBXLoader.cpp
//  nishikigoi
//
//  Created by David Kouril on 13/01/2018.
//

#include "FBXLoader.hpp"
#include "Utility.hpp"


MeshObject* FBXLoader::loadMeshObject(FbxNode* rootNote)
{
    std::vector<vec3> modelVertices;
    std::vector<uint> modelIndices;
    MeshObject * model = new MeshObject();
    
    FbxMesh* mesh = (FbxMesh*) rootNote->GetNodeAttribute();
    
    //~ model transformations
    FbxAMatrix& localTransform = rootNote->EvaluateLocalTransform();
    mat4 localTransMat = Utility::mayaToCinderMatrix(localTransform);
    model->setModelMatrix(localTransMat);
    
    //~ vertex positions
    FbxVector4* vertices = mesh->GetControlPoints();
    //mesh->normal
    //mesh->getnor
    for (int j = 0; j < mesh->GetControlPointsCount(); j++)
    {
        FbxVector4 vert = vertices[j];
        modelVertices.push_back(vec3(vert.mData[0], vert.mData[1], vert.mData[2]));
    }
    //~ polygons (indices)
    for (int j = 0; j < mesh->GetPolygonCount(); j++)
    {
        int numOfVertices = mesh->GetPolygonSize(j);
        if (numOfVertices != 3) return nullptr;
        
        for (int k = 0; k < numOfVertices; k++)
        {
            int controlPointIndex = mesh->GetPolygonVertex(j, k);
            modelIndices.push_back(controlPointIndex);
        }
    }
    model->setVertices(modelVertices);
    model->setIndices(modelIndices);
    
    //~ Rigging
    uint numOfDeformers = mesh->GetDeformerCount();
    
    for (int i = 0; i < numOfDeformers; i++)
    {
        FbxSkin* currentSkin = (FbxSkin*)mesh->GetDeformer(i, FbxDeformer::eSkin);
        
        if (!currentSkin) continue;
        
        uint numOfClusters = currentSkin->GetClusterCount();
        for (int j = 0; j < numOfClusters; j++)
        {
            FbxCluster * cluster = currentSkin->GetCluster(j);
            FbxNode* link = cluster->GetLink();
            
            uint vertexCount = cluster->GetControlPointIndicesCount();
            for (int k = 0; k < vertexCount; k++)
            {
                auto weight = cluster->GetControlPointWeights()[k];
            }
        }
    }
    
    return model;
}


JointObject* FBXLoader::loadSkeleton(FbxNode* rootNode)
{
    FbxSkeleton * root = (FbxSkeleton*) rootNode->GetNodeAttribute();
    
    FbxNode * current = rootNode;
    while (current->GetChildCount() > 0)
    {
        current = current->GetChild(0);
    }
}

std::vector<MeshObject*> FBXLoader::loadObjectFromFile(std::string fileName)
{
    FbxManager* manager = FbxManager::Create();
    
    FbxImporter* importer = FbxImporter::Create(manager,"");
    FbxScene* scene = FbxScene::Create(manager,"");
    
    auto modelPath = getAssetPath(fileName);
    bool success = importer->Initialize(modelPath.c_str());
    if(!success) return std::vector<MeshObject*>();
    
    success = importer->Import(scene);
    if(!success) return std::vector<MeshObject*>();
    
    importer->Destroy();
    
    std::vector<MeshObject*> loadedObjects;
    FbxNode* rootNode = scene->GetRootNode();
    if (rootNode)
    {
        int childCount = rootNode->GetChildCount();
        for (int i = 0; i < childCount; i++)
        {
            FbxNode* childNode = rootNode->GetChild(i);
            if (childNode->GetNodeAttribute() == NULL) continue;
            
            FbxNodeAttribute::EType attributeType = childNode->GetNodeAttribute()->GetAttributeType();
            if (attributeType == FbxNodeAttribute::eMesh)
            {
                MeshObject * mesh = loadMeshObject(childNode);
                loadedObjects.push_back(mesh);
            }
            else if(attributeType == FbxNodeAttribute::eSkeleton)
            {
                // load skeleton
            }
            
            
        }
    }
    //MeshObject * model = new MeshObject(modelVertices, modelIndices);
    
    return loadedObjects;
}
