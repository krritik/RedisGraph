/*
* Copyright 2018-2019 Redis Labs Ltd. and Contributors
*
* This file is available under the Apache License, Version 2.0,
* modified with the Commons Clause restriction.
*/

#ifndef __OP_COND_TRAVERSE_H
#define __OP_COND_TRAVERSE_H

#include "op.h"
#include "../../parser/ast.h"
#include "../../arithmetic/algebraic_expression.h"
#include "../../../deps/GraphBLAS/Include/GraphBLAS.h"
#include "../../util/vector.h"

/* OP Traverse */
typedef struct {
    OpBase op;
    Graph *graph;
    AlgebraicExpression *algebraic_expression;
    GrB_Matrix F;               // Filter matrix.
    GrB_Matrix M;               // Algebraic expression result.
    int *edgeRelationTypes;     // One or more relation types.
    int edgeRelationCount;      // length of edgeRelationTypes.
    Edge *edges;                // Discovered edges.
    GxB_MatrixTupleIter *iter;  // Iterator over M.
    int srcNodeRecIdx;          // Index into record.
    int destNodeRecIdx;         // Index into record.
    int edgeRecIdx;             // Index into record.
    int recordsCap;             // Max number of records to process.
    int recordsLen;             // Number of records to process.
    Record *records;            // Array of records.
    Record r;                   // Current selected record.
} CondTraverse;

/* Creates a new Traverse operation */
OpBase* NewCondTraverseOp(Graph *g, AlgebraicExpression *algebraic_expression);

/* TraverseConsume next operation 
 * each call will update the graph
 * returns NULL when no additional updates are available */
Record CondTraverseConsume(OpBase *opBase);

/* Restart iterator */
OpResult CondTraverseReset(OpBase *ctx);

/* Frees Traverse*/
void CondTraverseFree(OpBase *ctx);

#endif
