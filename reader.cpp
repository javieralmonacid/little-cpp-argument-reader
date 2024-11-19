#include <iostream>
#include <fstream>
#include <map>
#include <vector>

int main(int argc, char* argv[])
{
  // Declare a map to store key-value pairs
  std::map<std::string, std::string> args_map;

  // Loop through the command-line arguments
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];

    // Check if the argument starts with a dash '-'
    if (arg[0] != '-')
      throw std::invalid_argument("Invalid argument (does not start with '-'): " + arg);

    // Check if the argument contains '=' (i.e., key-value pair)
    size_t pos = arg.find('=');
    // Extract key from argument
    std::string key = arg.substr(0, pos);

    if (pos != std::string::npos) {
      // Extract value from argument if argument
      // does contain "="
      std::string value = arg.substr(pos + 1);

      // Insert the key-value pair into the map
      args_map[key] = value;
    } 
    else
    {
      // If argument does not contain "=", insert
      // the key-value pair with value="true"
      args_map[key] = "true";
    }
  }

  // Display the contents of the map
  std::cout << "Parsed pairs:" << std::endl;
  for (const auto& pair : args_map)
    std::cout << pair.first << " = " << pair.second << std::endl;

  return 0;
}