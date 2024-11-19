#include <iostream>
#include <fstream>
#include <map>
#include <vector>

int main(int argc, char* argv[])
{
  // Declare a map to store key-value pairs
  std::map<std::string, std::string> args_map;

  // Store default values
  args_map["-PARAMETERS"] = "parameters.prm";
  args_map["-BDY_STRAIN"] = "control_points_strain.dat";
  args_map["-ACTIVATION"] = "control_points_activation.dat";
  args_map["-ACTIVATION_LIST"] = "activation_list.dat";
  args_map["-QP_LIST_ONLY"] = "false";

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

    // Verify that the key is valid
    auto it = args_map.find(key);
    if (it == args_map.end())
      throw std::invalid_argument("Unsupported argument: " + key);

    // If argument contains "=", insert key-value pair,
    // otherwise insert key-"true" pair.
    if (pos != std::string::npos) 
    {
      // Extract value from argument
      std::string value = arg.substr(pos + 1);
      args_map[key] = value;
    } 
    else
      args_map[key] = "true";
  }

  // Display the contents of the map
  std::cout << "Parsed pairs:" << std::endl;
  for (const auto& pair : args_map)
    std::cout << pair.first << " = " << pair.second << std::endl;

  return 0;
}