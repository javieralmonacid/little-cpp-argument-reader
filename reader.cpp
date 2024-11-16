#include <iostream>
#include <fstream>
#include <map>
#include <vector>

int main(int argc, char* argv[])
{
  // Declare a map to store key-value pairs
  std::map<std::string, std::string> args_map;

  // Declare a vector to store single arguments
  std::vector<std::string> args_vec;

  // Loop through the command-line arguments
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];

    // Check if the argument starts with a dash '-'
    if (arg[0] != '-')
      throw std::invalid_argument("Invalid argument (does not start with '-'): " + arg);

    // Check if the argument contains '=' (i.e., key-value pair)
    size_t pos = arg.find('=');
    if (pos != std::string::npos) {
      // Extract key and value from the argument
      std::string key = arg.substr(0, pos);
      std::string value = arg.substr(pos + 1);

      // Insert the key-value pair into the map
      args_map[key] = value;
    } 
    else
    {
      // Insert the value into the vector
      args_vec.push_back(arg);
    }
  }

  // Display the contents of the map
  std::cout << "Parsed pairs:" << std::endl;
  for (const auto& pair : args_map)
    std::cout << pair.first << " = " << pair.second << std::endl;
  
  std::cout << "Parsed booleans:" << std::endl;
  for (const auto& elem : args_vec)
    std::cout << elem << std::endl;

  return 0;
}