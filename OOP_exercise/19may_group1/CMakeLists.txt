cmake_minimum_required(VERSION 3.0.0)
project(questionExam VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(questionExam main.cpp OpenQuestion.cpp Exam.cpp Question.cpp MultipleChoiceQuestion.cpp YesNoQuestion.cpp PossibleAnswer.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
