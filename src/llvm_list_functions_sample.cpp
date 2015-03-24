#include <string>
#include <iostream>

#include <llvm/Support/CommandLine.h>
#include <llvm/Support/MemoryBuffer.h>


std::unique_ptr<llvm::MemoryBuffer>&
get_memory_buffer_for_file(std::string file_name)
{
	llvm::ErrorOr<std::unique_ptr<llvm::MemoryBuffer>> memory_buffer =
		llvm::MemoryBuffer::getFile(file_name);

	if (memory_buffer.getError())
	{
		throw std::runtime_error("Cannot open bitcode file");
	}

	return memory_buffer.get();
}


int
main(int argc, char *args[])
{
	llvm::cl::opt<std::string> file_name(llvm::cl::Positional,
		llvm::cl::desc("bitcode_file"), llvm::cl::Required);

	llvm::cl::ParseCommandLineOptions(argc, args,
		"Lists functions from LLVM bitcode\n");

	try
	{
		get_memory_buffer_for_file(file_name).get();
	}
	catch(const std::runtime_error& error)
	{
		std::cerr <<error.what() <<"\n";
	}
}
