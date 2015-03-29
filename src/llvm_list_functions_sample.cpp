#include <string>

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


int
main(int argc, char *args[])
{
	llvm::cl::opt<std::string> file_name(llvm::cl::Positional,
		llvm::cl::desc("bitcode_file"), llvm::cl::Required);

	llvm::cl::ParseCommandLineOptions(argc, args,
		"Lists functions from LLVM bitcode\n");

	get_memory_buffer_from_bitcode_file(file_name);
}
