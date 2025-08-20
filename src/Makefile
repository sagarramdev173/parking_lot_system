CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
LDFLAGS = -lgtest -pthread

SRCDIR = .
BUILDDIR = build
TARGET = $(BUILDDIR)/parking_lot_system

_VEHICLE_SRC = $(wildcard $(SRCDIR)/vehicle/*.cpp)
_PARKING_LOT_SRC = $(wildcard $(SRCDIR)/parking_lot/*.cpp)
_MAIN_SRC = $(SRCDIR)/main.cpp

VEHICLE_OBJ = $(patsubst $(SRCDIR)/vehicle/%.cpp,$(BUILDDIR)/vehicle/%.o,$(_VEHICLE_SRC))
PARKING_LOT_OBJ = $(patsubst $(SRCDIR)/parking_lot/%.cpp,$(BUILDDIR)/parking_lot/%.o,$(_PARKING_LOT_SRC))
MAIN_OBJ = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(_MAIN_SRC))

TEST_SRCDIR = tests
_TEST_SRC = $(wildcard $(TEST_SRCDIR)/parking_lot/*.cpp) $(wildcard $(TEST_SRCDIR)/vehicle/*.cpp)
TEST_SRC = $(_TEST_SRC) $(TEST_SRCDIR)/main.cpp
TEST_OBJ = $(patsubst $(TEST_SRCDIR)/%.cpp,$(BUILDDIR)/$(TEST_SRCDIR)/%.o,$(TEST_SRC))
TEST_TARGET = $(BUILDDIR)/runTests

all: $(TARGET)

$(TARGET): $(VEHICLE_OBJ) $(PARKING_LOT_OBJ) $(MAIN_OBJ)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILDDIR)/vehicle/%.o: $(SRCDIR)/vehicle/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)/parking_lot/%.o: $(SRCDIR)/parking_lot/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)/$(TEST_SRCDIR)/%.o: $(TEST_SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ) $(VEHICLE_OBJ) $(PARKING_LOT_OBJ)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(VEHICLE_OBJ) $(PARKING_LOT_OBJ) $(MAIN_OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET)
	rm -rf $(BUILDDIR)/tests
	rm -rf $(BUILDDIR)/vehicle
	rm -rf $(BUILDDIR)/parking_lot
	rm -rf $(BUILDDIR)

.PHONY: all clean test
