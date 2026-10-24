#include "chunk.h"
#include "common.h"
#include "compiler.h"
#include "vm.h"

InterpretResult interpret(const char* source) {
  Chunk chunk;
  initChunk(&chunk);

  if (!compile(source, &chunk)) {
    freeChunk(&chunk);
    return INTERPRET_COMPILE_ERROR;
  }

  freeChunk(&chunk);
  return INTERPRET_OK;
}
