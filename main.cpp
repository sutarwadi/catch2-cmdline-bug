#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>
#include <chrono>
#include <iostream>

int main(int argc, char* argv[])
{
  Catch::Session session;

  namespace clara = Catch::clara;

  std::string data_basedir;
  std::string output_basedir;
  auto cli
      = session.cli()
      | clara::Arg(data_basedir,
          "path to test data")("Path to Test Data")
      | clara::Arg(output_basedir, "path to test output")(
          "Path to Test Output");

  session.cli(cli);

  int return_code = session.applyCommandLine(argc, argv);
  std::cout << return_code << "\n";
  if (return_code != 0) {
    return return_code;
  }
  return 0;
}
