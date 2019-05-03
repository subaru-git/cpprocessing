#pragma once

struct GLFWwindow;

namespace cp {
namespace core {

class Environment {
 public:
  Environment();
  ~Environment();

  GLFWwindow* size(int width, int height);
};

}  // namespace core
}  // namespace cp
