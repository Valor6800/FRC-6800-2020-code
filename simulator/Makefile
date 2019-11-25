SOURCES := $(wildcard *.cpp)
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))
DEPENDS := $(patsubst %.cpp,%.d,$(SOURCES))

# ADD MORE WARNINGS!
WARNING := -Wall -Wextra

# .PHONY means these rules get executed even if
# files of those names exist.
.PHONY: all clean

# The first rule is the default, ie. "make",
# "make all" and "make simulator" mean the same
all: simulator

clean:
	$(RM) $(OBJECTS) $(DEPENDS) simulator

# Linking the executable from the object files
simulator: $(OBJECTS)
	$(CXX) $(WARNING) $(CXXFLAGS) $^ -o $@

-include $(DEPENDS)

%.o: %.cpp Makefile
	$(CXX) $(WARNING) $(CXXFLAGS) -MMD -MP -c $< -o $@