/*
Copyright 2025 Antonio Bruce Webb

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
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
            void replaceState(int index, std::vector<float> newInputs, type newExpected, std::vector<Type> newRejected);
            void clear();
            ~DataSet();

        private:
            std::vector<std::vector<float>> inputs;
            std::vector<Type*> expectedOutputs;
            std::vector<std::vector<Type*>> rejectedOutputs;
            float maxValue;
            float minValue;
            float normalizedMin;
            float normalizedMax;
    };
}
