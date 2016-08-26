/*
 * File: dataStructure.h
 *----------------------------
 * In this file, following contents is included:
 * 1.data structures used  in this project is defined.And create the
 * 2. Declarations of functions which are used to create and build data structures.
 *
 * Simon Yang Summer 2016
 */
#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_
#include<set>
#include<vector>
#include<iostream>
#include<cstdlib>
#include<string>
#include<bitset>
#include<string.h>  /*for strlen()*/

using namespace std;

#define MAX_VERTEX_NUM 620
#define INFINITY_DISTANCE 100000
#define MAX_WEIGHT 10000
/*Define the data type used in this file*/
typedef int WeightType;      // Weight type  Ȩ����������
typedef int DataType;        //  Data type ���������������
typedef int Vertex;          // Vertex type ��������������
typedef int IDType;          // the  data type of ID of edge �ߵı����������

/*Define the structure of adjacent element */
/*�����ڽ�Ԫ�صĽṹ��*/
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex row;
	Vertex col;
	PtrToAdjVNode nextRight;
	WeightType weight;
	IDType edgeID;
};
typedef PtrToAdjVNode AdjV;

/*Define the adjacency list in the form of array*/
/*��������ʽ������һ���ڽӱ�*/
typedef struct VNode {
	PtrToAdjVNode firstEdge;
}AdjList[MAX_VERTEX_NUM];
//�����ǣ�����һ�����ͱ���adjlist�����������һ���ṹ������ΪԪ�����͵ĳ���ΪMaxVertexNum������

/*Define the structure of graph in the form of link list*/
/*�����ʾ��ͼ�Ľṹ�嶨��*/
typedef struct GNode *PtrToGNode;
struct GNode {
	int numVertex;
	int numEdge;
    AdjList Graph_row;
};
typedef PtrToGNode LGraph;

/*Define the structure of edge*/
/*�����Edge*/
typedef struct ENode *ptrToENode;
struct ENode {
	IDType edgeID;
	Vertex v1, v2;
	WeightType weight ;
};
typedef ptrToENode Edge;

/*Define  a structure  to describe a position in matrix*/
typedef struct PosNode *ptrToPosNode;
struct PosNode{
    int r;     // the row index
    int c;     // the column index
};
typedef  ptrToPosNode Pos;

/*Define the structure of record that stores the weight and the path*/
typedef struct RecordNode *ptrToRecordNode;
struct RecordNode{
	WeightType weightSum;
	vector<IDType> path;
};
typedef ptrToRecordNode Record;

/*--------------------------------Function Declaration Part-------------------------------------------------------------------*/

/*
 * Function: BuildAllEdges
 * Usage: BuildAllEdges(topo, edge_num)
 * ----------------------
 * Build all the edges using information stored in the topo,and put the edges in a vector.
 */
vector<Edge> BuildAllEdges(char* topo[5000], int edge_num);
/*
 * Function: CharToEdge
 * Usage: CharToEdge(edge)
 * ----------------------
 * Convert the char* which contains the information of edge to an integer array.
 */
int* CharToEdge(char *edge);
/*
 * Function: CreateEdge
 * Usage: CharToEdge(arr);
 * ----------------------
 * Create an edge.
 */
Edge CreateEdge(int* array);

/*
 * Function: InsertSelfToSelfEdge
 * Usage: InsertSelfToSelfEdge(gra, numV,visitVertexes,p_source,p_dest);
 * ----------------------
 * Insert edge f(i,i) = 0 for the vertex not in the visit vertexes set(Except the source and destination vertex).
 */
void InsertSelfToSelfEdge(LGraph gra,int numV,bitset<MAX_VERTEX_NUM>& visit,Vertex &p_source,Vertex &p_dest);
/*
 * Function: BuildGraph
 * Usage: gra = BuildGraph(numV, all_edges, p_source, p_dest);
 * ----------------------
 * Build the Graph in link list form,store the graph information in this graph.
 */
LGraph BuildGraph(int numV, vector<Edge> &all_edges,Vertex &p_source,Vertex &p_dest);
/*
 * Function: CreateGraph
 * Usage: gra = CreateGraph(numV);
 * ----------------------
 * Initialize a graph with numV vertexes but without any edge.
 */
LGraph CreateGraph(int numV);
/*
 * Function: InsertEdge
 * Usage: InsertEdge(gra, e, p_source, p_dest);
 * ----------------------
 * Insert an edge to the graph.
 */
void InsertEdge(LGraph gra, Edge e,Vertex &p_source,Vertex &p_dest);
/*
 * Function: GetVertexesNum
 * Usage: GetVertexesNum(all_edges);
 * ----------------------
 * Count vertexes, and return the number of vertexes.
 */
int GetVertexesNum(vector<Edge> &all_edges);
/*
 * Function: ConvertDemandSet
 * Usage: ConvertDemandSet(demand);
 * ----------------------
 * Convert the char*  demand which contains the information of vertexes should be visited to an integer array.
 */
vector<Vertex> ConvertDemandSet(char *demand);
/*
 * Function: BuildVisitVertexSet
 * Usage: BuildVisitVertexSet(demandArray, p_source, p_dest, m_size);
 * ----------------------
 * Build visit vertexes set that demanded,return the visit vertex set.
 */
bitset<MAX_VERTEX_NUM> BuildVisitVertexSet(vector<Vertex> &demandArray,Vertex &p_source,Vertex &p_dest,int &m_size);


#endif
