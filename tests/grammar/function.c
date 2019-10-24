#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>

#include <munit/munit.h>

#include <grammar.h>
#include <parse.h>
#include <token.h>

#include <suite.h>

/*
    It should be noted that this test presently only exercises the grammar for 
    function declarations and does not extensively validate the parse tokens 
    subsequently returned.
*/

//  xxd -i src/factorial.txt

char _Source[] = {
    0x46, 0x55, 0x4e, 0x43, 0x54, 0x49, 0x4f, 0x4e, 
    0x20, 0x66, 0x61, 0x63, 0x74, 0x20, 0x3a, 0x20, 
    0x55, 0x44, 0x49, 0x4e, 0x54, 0x0a, 0x56, 0x41, 
    0x52, 0x5f, 0x49, 0x4e, 0x50, 0x55, 0x54, 0x20, 
    0x69, 0x6e, 0x70, 0x3a, 0x20, 0x55, 0x44, 0x49, 
    0x4e, 0x54, 0x3b, 0x20, 0x45, 0x4e, 0x44, 0x5f,
    0x56, 0x41, 0x52, 0x0a, 0x56, 0x41, 0x52, 0x5f, 
    0x4f, 0x55, 0x54, 0x50, 0x55, 0x54, 0x20, 0x6f, 
    0x75, 0x74, 0x3a, 0x20, 0x55, 0x44, 0x49, 0x4e, 
    0x54, 0x3b, 0x20, 0x45, 0x4e, 0x44, 0x5f, 0x56, 
    0x41, 0x52, 0x0a, 0x56, 0x41, 0x52, 0x20, 0x6c, 
    0x6f, 0x63, 0x61, 0x6c, 0x3a, 0x20, 0x55, 0x44,
    0x49, 0x4e, 0x54, 0x3b, 0x20, 0x45, 0x4e, 0x44, 
    0x5f, 0x56, 0x41, 0x52, 0x0a, 0x0a, 0x4c, 0x44, 
    0x20, 0x69, 0x6e, 0x70, 0x0a, 0x47, 0x45, 0x20, 
    0x31, 0x0a, 0x4a, 0x4d, 0x50, 0x43, 0x20, 0x6e, 
    0x6f, 0x6e, 0x7a, 0x65, 0x72, 0x6f, 0x0a, 0x4c, 
    0x44, 0x20, 0x31, 0x0a, 0x52, 0x45, 0x54, 0x0a,
    0x6e, 0x6f, 0x6e, 0x7a, 0x65, 0x72, 0x6f, 0x3a, 
    0x20, 0x4c, 0x44, 0x20, 0x69, 0x6e, 0x70, 0x0a, 
    0x53, 0x55, 0x42, 0x20, 0x31, 0x0a, 0x53, 0x54, 
    0x20, 0x6c, 0x6f, 0x63, 0x61, 0x6c, 0x0a, 0x66, 
    0x61, 0x63, 0x74, 0x20, 0x6c, 0x6f, 0x63, 0x61, 
    0x6c, 0x0a, 0x4d, 0x55, 0x4c, 0x20, 0x69, 0x6e,
    0x70, 0x0a, 0x53, 0x54, 0x20, 0x6f, 0x75, 0x74, 
    0x0a, 0x52, 0x45, 0x54, 0x0a, 0x0a, 0x45, 0x4e, 
    0x44, 0x5f, 0x46, 0x55, 0x4e, 0x43, 0x54, 0x49, 
    0x4f, 0x4e, 0x0a, 0x00
  
};


MunitResult
test_grammar_function(const MunitParameter Parameters[], void *Fixture) {
    ECHIDNA *pContext;
    LLE *pElement;
    PARSE *pParse;
    TOKEN *pToken;
    TOKEN_LIST *pList;

    pContext = (ECHIDNA *) Fixture;
    munit_assert_not_null(pContext);
    munit_assert_int(test_parse(pContext, _Source), ==, 0);

    munit_assert_not_null(pParse = &pContext->Parse);
    munit_assert_not_null(pList = &pParse->Tokens);
    munit_assert_size(pList->List.Size, ==, 1);
    munit_assert_not_null(pElement = pList->List.Head);

    munit_assert_not_null(pToken = (TOKEN *) pElement->Data);
    munit_assert_int(pToken->Id, ==, TYPE);
    munit_assert_int(pToken->Type, ==, TYPE_LIST);
    pList = (TOKEN_LIST *) pToken;
    munit_assert_size(pList->List.Size, ==, 1);
    munit_assert_not_null(pElement = pList->List.Head);

    munit_assert_not_null(pToken = (TOKEN *) pElement->Data);
    munit_assert_int(pToken->Id, ==, FUNCTION);
    munit_assert_int(pToken->Type, ==, TYPE_LIST);
    pList = (TOKEN_LIST *) pToken;
    munit_assert_size(pList->List.Size, ==, 2);
    munit_assert_not_null(pToken->Name);
    munit_assert_string_equal(pToken->Name, "fact");
    munit_assert_uint32(pToken->Value.Type, ==, TYPE_UDINT);
    munit_assert_not_null(pElement = pList->List.Head);

    return MUNIT_OK;
}


