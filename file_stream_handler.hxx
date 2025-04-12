#ifndef FSH_HXX
#define FSH_HXX

#include <filesystem>

#include <sys/types.h>

typedef std::basic_ifstream<char> file_input_stream;
typedef std::basic_ofstream<char> file_output_stream;


class file_stream_handler{
	private:
	file_input_stream *_open_file_input_stream(const std::filesystem::path &file_path);
	file_output_stream *_open_file_output_stream(const std::filesystem::path &file_path);

	public:
	file_stream_handler(const file_stream_handler &) = delete;
	file_stream_handler(file_stream_handler &&) = delete;
	file_stream_handler &operator=(const file_stream_handler &) = delete;
	file_stream_handler &operator=(file_stream_handler &&) = delete;
	/**
	 * Returns a pointer to an input stream stored on the heap.
	 * Does not manage or own the pointer. requires manual deletion to
	 * free memory.
	 */
	file_input_stream *open_file_input_stream(const std::filesystem::path input_file_path);

	/**
	 * Returns a pointer to an input stream stored on the heap.
	 * Does not manage or own the pointer. requires manual deletion to
	 * free memory.
	 */
	file_input_stream *open_file_input_stream(const std::filesystem::path &input_file_path);

	/**
	 * Returns a pointer to an output stream stored on the heap.
	 * Does not manage or own the pointer. requires manual deletion to
	 * free memory.
	 */
	file_output_stream *open_file_output_stream(const std::filesystem::path output_file_path);

	/**
	 * Returns a pointer to an output stream stored on the heap.
	 * Does not manage or own the pointer. requires manual deletion to
	 * free memory.
	 */
	file_output_stream *open_file_output_stream(const std::filesystem::path &output_file_path);

	/**
	 * Closes the file stream without freeing the object.
	 * delete the pointer to free memory.
	 */
	void close_file_stream(file_input_stream *input_stream);

	/**
	 * Closes the file stream without freeing the object.
	 * delete the pointer to free memory.
	 */
	void close_file_stream(file_output_stream *output_stream);

};

typedef file_stream_handler FSH;
typedef file_input_stream FIS;
typedef file_output_stream FOS;

#endif
