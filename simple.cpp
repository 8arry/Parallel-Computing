#include <taskflow/taskflow.hpp>  // Taskflow is header-only
#include <fstream>                // 添加头文件用于文件输出

int main(){
  
  tf::Executor executor;
  tf::Taskflow taskflow;

  auto [A, B, C, D] = taskflow.emplace(  // create four tasks
    [] () { std::cout << "TaskA\n"; },
    [] () { std::cout << "TaskB\n"; },
    [] () { std::cout << "TaskC\n"; },
    [] () { std::cout << "TaskD\n"; } 
  );                                  
                                      
  A.precede(B, C);  // A runs before B and C
  D.succeed(B, C);  // D runs after  B and C

  // 输出DAG为Graphviz dot格式
  std::ofstream ofs("dag.dot");
  taskflow.dump(ofs);

  executor.run(taskflow).wait(); 

  return 0;
}