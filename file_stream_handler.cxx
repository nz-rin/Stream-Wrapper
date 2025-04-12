#include <cstring>
#include <iostream>
#include <fstream>

#include "file_stream_handler.hxx"

// Internal Functions
file_input_stream *file_stream_handler::_open_file_input_stream(const std::filesystem::path &file_path){
	if( !std::filesystem::exists(file_path) ){
		std::cerr << "[ERROR] Failed to open input stream: " << file_path << '\n';
		exit(EXIT_FAILURE);
	}
	file_input_stream *is = new file_input_stream(file_path);
	if(!is){
		std::cerr << "[ERROR] Failed to create input file stream: " << file_path << '\n' << strerror(errno);
		exit(EXIT_FAILURE);
	}

	return is;
}

file_output_stream *file_stream_handler::_open_file_output_stream(const std::filesystem::path &file_path){
	if( !std::filesystem::exists(file_path) ){
		std::cerr << "[ERROR] Failed to open output stream: " << file_path << '\n' << strerror(errno);
		exit(EXIT_FAILURE);
	}
	file_output_stream *os = new file_output_stream(file_path);
	if(!os){
		std::cerr << "[ERROR] Failed to create output file stream: " << file_path << '\n';
		exit(EXIT_FAILURE);
	}

	return os;
}

// Wrapppers

file_input_stream *file_stream_handler::open_file_input_stream(const std::filesystem::path &file_path){
	return _open_file_input_stream(file_path);
}

file_input_stream *file_stream_handler::open_file_input_stream(const std::filesystem::path file_path){
	return _open_file_input_stream(file_path);
}


file_output_stream *file_stream_handler::open_file_output_stream(const std::filesystem::path &file_path){
	return _open_file_output_stream(file_path);
}
file_output_stream *file_stream_handler::open_file_output_stream(const std::filesystem::path file_path){
	return _open_file_output_stream(file_path);
}

// closes streams

void close_file_stream(file_input_stream *input_stream){
	if(input_stream->is_open())
		input_stream->close();
}
void close_file_stream(file_output_stream *output_stream){
	if(output_stream->is_open())
		output_stream->close();
}
