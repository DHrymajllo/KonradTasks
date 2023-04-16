/*
// --------- TASK 1 ---------

#include <iostream>
#include <cstdint>

// function which will return given amount of bits with desired shift
uint32_t GetBitsFromUint32(uint32_t inputValue, uint8_t bitOffset, uint8_t bitLength) {
	// create bit mask for desired bit length
	uint32_t bitMask = (1u << bitLength) - 1u;
	// shift the mask to desired bit offset
	bitMask <<= bitOffset;
	// apply the mask to the input value
	uint32_t result = inputValue & bitMask;
	// shift the result back to the starting bit position
	result >>= bitOffset;
	return result;
}

//example:
int main() {
	uint32_t res = GetBitsFromUint32(0xABCDEF12, 4, 12);
	std::cout << std::hex << res << std::endl; // result is: 0xef1
	return 0;
}
*/

/*
// --------- TASK 2 ---------

#include <iostream>
#include <string>
#include <cstdint>

uint32_t GetBitsFromUint32(uint32_t inputValue, uint8_t bitOffset, uint8_t bitLength) {
    // Shift the input value right by the bit offset
    inputValue >>= bitOffset;

    // Zero out the bits higher than bitLength
    uint32_t mask = (1 << bitLength) - 1;
    return inputValue & mask;
}

uint32_t GetBitsFromUint32(const char* inputValue, uint8_t bitOffset, uint8_t bitLength) {
    // Convert the input value from a string to a uint32_t
    uint32_t value = std::stoul(inputValue, nullptr, 16);

    // Call the other overload of the function
    return GetBitsFromUint32(value, bitOffset, bitLength);
}

int main() {
    uint32_t res1 = GetBitsFromUint32(0xABCDEF12, 4, 12);
    uint32_t res2 = GetBitsFromUint32("0xABCDEF12", 4, 12);

    std::cout << std::hex << res1 << std::endl; // Expected output: ef1
    std::cout << std::hex << res2 << std::endl; // Expected output: ef1

    return 0;
}
*/

/*
// --------- TASK 3 ---------

#include <iostream>
#include <bitset>
#include <vector>
#include <string>

std::vector<bool> GetBitsVector(uint32_t inputValue) {
    std::bitset<32> bitset(inputValue);
    std::vector<bool> bits(bitset.size());
    for (size_t i = 0; i < bitset.size(); i++) {
        bits[i] = bitset[i];
    }
    return bits;
}

std::vector<bool> GetBitsVector(std::string inputValue) {
    uint32_t value = std::stoi(inputValue, nullptr, 0);
    return GetBitsVector(value);
}

int main() {
    std::vector<bool> res1 = GetBitsVector(149);
    std::vector<bool> res2 = GetBitsVector(0x95);
    std::vector<bool> res3 = GetBitsVector("0x95");

    for (const auto& bit : res1) {
        std::cout << bit << " ";
    }
    std::cout << std::endl;

    for (const auto& bit : res2) {
        std::cout << bit << " ";
    }
    std::cout << std::endl;

    for (const auto& bit : res3) {
        std::cout << bit << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/

/*
// --------- TASK 4 ---------
#include <iostream>
#include <vector>
#include <string>

class Tree {
public:
    Tree(std::string name) : name(name) {}
    ~Tree() { for (auto child : children) delete child; }
    Tree* AddSub(std::string name) {
        Tree* sub = new Tree(name);
        children.push_back(sub);
        return sub;
    }
    uint32_t GetSubCount() const { return children.size(); }
    uint32_t GetAllSubCount() const {
        uint32_t count = children.size();
        for (auto child : children) count += child->GetAllSubCount();
        return count;
    }
    void Del(uint32_t index) {
        if (index < children.size()) {
            delete children[index];
            children.erase(children.begin() + index);
        }
    }
    void print(int indent) const {
        for (int i = 0; i < indent; ++i) std::cout << "  ";
        std::cout << name << std::endl;
        for (auto child : children) child->print(indent + 1);
    }
private:
    std::string name;
    std::vector<Tree*> children;
};

int main() {
    Tree* root = new Tree("tree name");
    Tree* galaz1 = root->AddSub("galaz 1");
    Tree* galaz2 = root->AddSub("galaz 2");
    Tree* galaz3 = root->AddSub("galaz 3");
    Tree* galaz1_1 = galaz1->AddSub("galaz 1.1");
    Tree* galaz2_1 = galaz2->AddSub("galaz 2.1");
    Tree* galaz2_2 = galaz2->AddSub("galaz 2.2");
    Tree* galaz2_1_1 = galaz2_1->AddSub("galaz 2.1.1");

    root->print(0);

    uint32_t rootChildrenCnt = root->GetSubCount();
    uint32_t galaz1childrenCount = galaz1->GetSubCount();
    uint32_t countOfAllChildren = root->GetAllSubCount();

    root->Del(1);

    uint32_t rootChildrenCnt_v2 = root->GetSubCount();
    uint32_t countOfAllChildren_v2 = root->GetAllSubCount();

    delete(root);

    return 0;
}
*/

/*
// --------- TASK 5 ---------
#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    Node(const std::string& name) : name_(name) {}

    Node* AddChild(const std::string& child_name) {
        Node* child = new Node(child_name);
        children_.push_back(child);
        return child;
    }

    void Del(size_t index) {
        if (index < children_.size()) {
            delete children_[index];
            children_.erase(children_.begin() + index);
        }
    }

    void print(int depth = 0, bool print_numbers = false, const std::string& prefix = "") {
        std::string indentation(depth * 3, ' ');
        std::string number_prefix = print_numbers ? prefix : "";
        std::cout << indentation << number_prefix << name_ << std::endl;

        for (size_t i = 0; i < children_.size(); ++i) {
            std::string child_prefix = print_numbers ? (prefix + std::to_string(i + 1) + ".") : "";
            children_[i]->print(depth + 1, print_numbers, child_prefix);
        }
    }

private:
    std::string name_;
    std::vector<Node*> children_;
};

int main() {
    Node* root = new Node("tree name");
    Node* branch1 = root->AddChild("galaz 1");
    branch1->AddChild("galaz 1.1");
    Node* branch2 = root->AddChild("galaz 2");
    branch2->AddChild("galaz 2.1")->AddChild("galaz 2.1.1");
    branch2->AddChild("galaz 2.2");
    root->AddChild("galaz 3");

    root->print(0, true); // deepth= 0, true = print numbers
    std::cout << std::endl;

    root->Del(1); // remove second child

    root->print(0, true);
    std::cout << std::endl;

    delete root;

    return 0;
}
*/

/*
// --------- TASK 6 ---------
#include <iostream>
#include <vector>

template <typename T>
void printVectorInReverse(const std::vector<T>& vec, size_t index) {
    if (index == 0) {
        std::cout << vec[index] << std::endl;
        return;
    }
    std::cout << vec[index] << ",";
    printVectorInReverse(vec, index - 1);
}

int main() {
    std::vector<char> inputVector = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };

    printVectorInReverse(inputVector, inputVector.size() - 1);

    return 0;
}
*/

/*
// --------- TASK 7 ---------
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdint>

typedef unsigned int uint32;

class BitStream {
private:
    std::vector<uint8_t> buffer;
    uint32 bitPosition;

public:
    BitStream() : bitPosition(0) {
        buffer.resize(8);
    }

    uint32 Add(uint32 bitLength, void* dataAddr) {
        uint32 byteOffset = bitPosition / 8;
        uint32 bitOffset = bitPosition % 8;
        uint8_t* bytePtr = buffer.data() + byteOffset;
        uint8_t* dataPtr = static_cast<uint8_t*>(dataAddr);

        uint8_t mask = (1 << bitLength) - 1;
        uint8_t bits = *dataPtr & mask;

        if (bitOffset + bitLength <= 8) {
            *bytePtr |= bits << (8 - bitOffset - bitLength);
        }
        else {
            *bytePtr |= bits >> (bitLength - (8 - bitOffset));
            *(bytePtr + 1) |= bits << (16 - bitOffset - bitLength);
        }

        bitPosition += bitLength;
        return bitPosition;
    }

    uint32 Get(uint32 bitLength, void* dataAddr) {
        uint32 byteOffset = bitPosition / 8;
        uint32 bitOffset = bitPosition % 8;
        uint8_t* bytePtr = buffer.data() + byteOffset;
        uint8_t* dataPtr = static_cast<uint8_t*>(dataAddr);

        uint8_t mask = (1 << bitLength) - 1;

        if (bitOffset + bitLength <= 8) {
            *dataPtr = (*bytePtr >> (8 - bitOffset - bitLength)) & mask;
        }
        else {
            uint8_t bits1 = *bytePtr << bitOffset;
            uint8_t bits2 = *(bytePtr + 1) >> (8 - bitLength + bitOffset);
            *dataPtr = (bits1 | bits2) & mask;
        }

        bitPosition += bitLength;
        return bitPosition;
    }

    uint32 GetBitLength() {
        return bitPosition;
    }

    uint32 GetData(void* addr, uint32 maxBitLength) {
        uint32 byteLength = (maxBitLength + 7) / 8;
        uint32 dataLength = std::min(static_cast<uint32>(buffer.size()), byteLength);
        std::memcpy(addr, buffer.data(), dataLength);
        return dataLength * 8;
    }

    void ResetData() {
        buffer.clear();
        buffer.resize(8);
        bitPosition = 0;
    }
};

int main() {
    BitStream bs;

    uint32 var0 = 5;
    uint16_t var5 = 0x1234;
    uint32 var2 = 23;

    bs.Add(4, &var0);
    bs.Add(16, &var5);
    bs.Add(5, &var2);

    uint32 result0, result2;
    uint16_t result5;
    bs.Get(4, &result0);
    bs.Get(16, &result5);
    bs.Get(5, &result2);

    std::cout << "Result0: " << result0 << std::endl;
    std::cout << "Result5: " << result5 << std::endl;
    std::cout << "Result2: " << result2 << std::endl;

    return 0;
}
*/