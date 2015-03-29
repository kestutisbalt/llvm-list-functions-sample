#include <string>
#include <iostream>
#include <vector>

#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/MemoryBuffer.h>


std::unique_ptr<llvm::MemoryBuffer>
get_memory_buffer_from_bitcode_file(const std::string& file_name)
{
	auto memory_buffer = llvm::MemoryBuffer::getFile(file_name);

	if (memory_buffer.getError())
	{
		throw std::runtime_error("Failed to open bitcode file");
	}

	return std::move(memory_buffer.get());
}


std::vector<std::string>
parse_functions_from_module(const llvm::Module *module)
{
	std::vector<std::string> functions;

	for (llvm::Module::const_iterator i =
		module->getFunctionList().begin();
		i != module->getFunctionList().end(); i++)
	{
		if (!i->isDeclaration())
		{
			functions.push_back(i->getName().str());
		}
	}

	return functions;
}


int
main(int argc, char *args[])
{
	llvm::cl::opt<std::string> file_name(llvm::cl::Positional,
		llvm::cl::desc("bitcode_file"), llvm::cl::Required);

	llvm::cl::ParseCommandLineOptions(argc, args,
		"Lists functions from LLVM bitcode\n");
}
