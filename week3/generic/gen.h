#include "gen.c"
SymbolTable creatSymbolTable( Entry (*makeNode)(void *, void *), int (*compare)(void*, void*) );
void dropSymbolTable(SymbolTable *tab);
void addEntry(void* key, void* value, SymbolTable *tab);
Entry* getEntry(void *key, SymbolTable tab);
