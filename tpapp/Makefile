PROJECT_NAME := tpapp

CXX := g++
CXXFLAGS := -std=c++17 -Wall

MAIL_LIB_INC_DIR := ../mail-lib/include
MAIL_LIB_PATH := ../mail-lib/build

INC_DIR := include

SRC_DIR := src
BIN_DIR := bin
BUILD_DIR := build

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp $(SRC_DIR)/*/*/*.cpp)
DEP_FILES := $(SRC_FILES:.cpp=.d)
OBJ_FILES := $(SRC_FILES:.cpp=.o)

-include $(addprefix $(BUILD_DIR)/,$(DEP_FILES))

run: $(BIN_DIR)/$(PROJECT_NAME)
	@LD_LIBRARY_PATH=$(MAIL_LIB_PATH) $(BIN_DIR)/$(PROJECT_NAME)

build: $(BIN_DIR)/$(PROJECT_NAME)

$(BIN_DIR)/$(PROJECT_NAME): $(addprefix $(BUILD_DIR)/,$(OBJ_FILES))
	@echo "🔧 Preparing app ..."
	@mkdir -p $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) $^ -o $@ -L $(MAIL_LIB_PATH) -l mail

$(BUILD_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "🏛️ Building $< ..."
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -I $(MAIL_LIB_INC_DIR) -I $(INC_DIR) -MMD -MP -c $< -o $@

clean:
	@echo "🧹 Cleaning ..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR)