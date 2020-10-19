#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/Instructions.h"
#include <iterator>
using namespace llvm;

namespace {
  struct SkeletonPass : public FunctionPass {
    static char ID;
    SkeletonPass() : FunctionPass(ID) {}

    virtual bool runOnFunction(Function &F) {
      bool unmodified = true;
      for (auto& B : F) {
        for (auto i = B.begin(); i != B.end();) {
          auto &I = *i;
          if (auto* call = dyn_cast<CallInst>(&I)) {
            if (call->getCalledFunction() && call->getCalledFunction()->getName()=="printf") {
              i = I.eraseFromParent();
              unmodified = false;
              continue;
            }
          }
          ++i;
        }
      }
      return unmodified;
    }
  };
}

char SkeletonPass::ID = 0;

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerSkeletonPass(const PassManagerBuilder &,
                         legacy::PassManagerBase &PM) {
  PM.add(new SkeletonPass());
}
static RegisterStandardPasses
  RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                 registerSkeletonPass);
