# KonradTasks<br>
// --------- TASK 1 ---------<br>
// function which will return given amount of bits with desired shift<br>
uint32 GetBitsFromUint32(unit32 inputValue, uint8 bitOffset, uint8bitLength);<br>
//example:<br>
uint32 res = GetBitsFromUint32(0xABCDEF12, 4, 12);<br>
// result is: res = 0x00000EF1;<br>

// --------- TASK2 ---------<br>
//overload function with const char *:<br>
uint32 GetBitsFromUint32(const char* inputValue, uint8 bitOffset, uint8 bitLength);<br>
uint32 res = GetBitsFromStr("0xABCDEF12", 4, 12); // pay attention to quotation!<br>
// result shall be the same<br>
// res = 0x00000EF1;<br>

// --------- TASK 3 ---------<br>
// Extract bool vector from overloaded function<br>
std::vector<bool> GetBitsVector(std::string inputValue);<br>
std::vector<bool> GetBitsVector(uint32 inputValue);<br>
// usage:<br>
std::vector<bool> res = GetBitsVector(149);<br>
// or<br>
std::vector<bool> res = GetBitsVector(0x95);<br>
// or<br>
std::vector<bool> res = GetBitsVector("0x95");<br>
// expected result (index 0 = LSB)<br>
// res = {true, false, true, false, true, false, false, true, ...}<br>

// --------- TASK 4 ---------<br>
// Create Tree class which will be able to generate string trees (like folders structure)<br>
// example of usage:<br>
int main(...)<br>
{<br>
   Tree* root = new Tree("tree name");<br>
   Tree* galaz1 = root->AddSub("galaz 1"); // this function creates a child Tree object and returns pointer to it<br>
   Tree* galaz2 = root->AddSub("galaz 2");<br>
   Tree* galaz3 = root->AddSub("galaz 3");<br>
   Tree* galaz1_1 = galaz1->AddSub("galaz 1.1");<br>
   Tree* galaz2_1 = galaz2->AddSub("galaz 2.1");<br>
   Tree* galaz2_2 = galaz2->AddSub("galaz 2.2");<br>
   Tree* galaz2_1_2 = galaz2_1->AddSub("galaz 2.1.2");<br>
   // after execution<br>
   root->print(0); // in parameter pass initial indent for the object<br>
   // Expected result:<br>
   // tree name<br>
   //    galaz 1<br>
   //       galaz 1.1<br>
   //    galaz 2<br>
   //       galaz 2.1<br>
   //        galaz 2.1.1<br>
   //       galaz 2.2<br>
   //    galaz 3<br>
   // print works recursive, where indent is passed<br>
   uint32 rootChildrenCnt = root->GetSubCount(); // result shall be 3<br>
   uint32 galaz1childrenCount = galaz1->GetSubCount(); // result shall be 1<br>
   uint32 countOfAllChildren = root->GetAllSubCount(); // result shall be 7 (recursive children counting)<br>
   root->Del(1); // will remove galaz_2 with all it's children (recursive), so in a result only galaz_1 and galaz_3 will stay<br>
   uint32 rootChildrenCnt _v2 = root->GetSubCount(); // result shall be 2<br>
   uint32 countOfAllChildren _v2 = root->GetAllSubCount(); // result shall be 3 (recursive children counting)<br>
   delete(root); // deleting root shall remove all children (recursive) and clean memory<br>
}<br>

// --------- TASK 5 ---------<br>
// Extension of "print" function which will add automatic numbering<br>
// execution:<br>
root->print(0, true); // deepth= 0, true = print numbers<br>
   // We shall get following result (root has no number)<br>
   // tree name<br>
   //    1. galaz 1<br>
   //       1.1. galaz 1.1<br>
   //    2. galaz 2<br>
   //       2.1. galaz 2.1<br>
   //        2.1.1. galaz 2.1.1<br>
   //       2.2. galaz 2.2<br>
   //    3. galaz 3<br>
// remove second child:<br>
root->Del(1);<br>
// result:<br>
// tree name<br>
//    1. galaz 1<br>
//       1.1. galaz 1.1<br>
//    2. galaz 3<br>

// ---------------- TASK 6 ---------------<br>
// Develop function, which will show all elements of vector in reverse order without (!) usage of any loops or libraries.<br>
// input vector: { a,b,c,d,e,f,g,h,i,j }<br>
// output:<br>
// j,i,h,g,f,e,d,c,b,a<br>

// ---------------- TASK 7 ----------------<br>
Prepare class / set of functions, which allows serialization and deserialization of binary data, like:<br>
BitStream->Add(4, &Var0) // adds 4 bits of Var0 to a data stream / buffer<br>
BitStream->Add(2, &Var1)// adds 2 bits of Var1 to a data stream / buffer<br>
BitStream->Add(5, &Var2)// adds 5 bits of Var2 to a data stream / buffer<br>
BitStream->Add(1, &Var3)// adds 1 bit of Var3 to a data stream / buffer<br>
BitStream->Add(8, &Var4)// adds 8 bits of Var4 to a data stream / buffer<br>
BitStream->Add(16, &Var5)// adds 16 bits of Var5 to a data stream / buffer<br>
BitStream->Add(4, &Var6)// adds 4 bits of Var6 to a data stream / buffer<br>
// Var0..6 can be any type<br>
Function samples:<br>
uint32 BitStream::Add(uint32 bitLength, void * dataAddr); //returnsactual position after adding data to stream<br>
uint32 BitStream::Get(uint32 bitLength, void*dataAddr); // returns position after reading bits and storing unter dataAddr<br>
uint32 BitStream::GetBitLength(); // returns amount of added bits <br>
uint32 BitStream::GetData(void * addr, uint32 maxBitLength); // allows to get full stream, returns  number of bits<br>
BitStream::ResetData(); // clears internal buffer<br>

![image](https://user-images.githubusercontent.com/44548837/232313833-faf89916-c2f4-4ab5-8d3c-33e41389449f.png)
