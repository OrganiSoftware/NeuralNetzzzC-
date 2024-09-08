#ifndef DataSet
#define DataSet


namespace NeuralNetzzz
{   
    template<typename Type>
    class DataSet
    {
        public:
            DataSet(float maxValue, float minValue);
            void addState(std::vector<float> inputs, type expectedOutput, std::vector<Type> rejectedOutputs);
            void storeInJSON(string path);
            void JSONLoad(string path, int sizeOfSubset);
            void deleteState(int index);
            void replaceState(int index);
            void clear();
            ~DataSet();

        private:
            std::vector<std::vector<float>> inputs;
            std::vector<Type> expectedOutputs;
            std::vector<std::vector<Type>> rejectedOutputs;
            float maxValue;
            float minValue;
            float normalizedMin;
            float normalizedMax;
    };
}