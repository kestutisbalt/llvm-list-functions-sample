#include <string>
#include <vector>
#include <iostream>

#include <llvm/Support/CommandLine.h>
#include <llvm/Support/MemoryBuffer.h>


int
main(int argc, char *args[])
{
	llvm::cl::opt<std::string> file_name(llvm::cl::Positional,
		llvm::cl::desc("bitcode_file"), llvm::cl::Required);

	llvm::cl::ParseCommandLineOptions(argc, args,
		"Lists functions from LLVM bitcode\n");
}
