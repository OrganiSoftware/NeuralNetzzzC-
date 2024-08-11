#ifndef DataSet
#define DataSet

namespace NeuralNetzzz
{   
    template<typename Type>
    class DataSet
    {
        public:
            DataSet(float maxValue, float minValue);
            void addState(float *inputs, Type *expectedOutputs, Type *rejectedOutputs);
            void storeInJSON(string path);
            void JSONLoad(string path, int sizeOfSubset);
            bool deleteState(int index);
            bool replaceState(int index, )

        private:
            float *dataSet;
            Type *expectedOutputs;
            Type *rejectedOutputs;
            float maxValue;
            float minValue;


        

    };
}