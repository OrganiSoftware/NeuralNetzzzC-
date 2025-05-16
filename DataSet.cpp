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
#include<DataSet.h>
#include<iostream>
#include<vector>
#include <json/value.h>
#include <fstream>

using namespace NeuralNetzzz;
using namespace std;
using namespace Json;

NeuralNetzzz::DataSet::DataSet(float maxValue, float minValue)
{
    this.maxValue = maxValue;
    this.minValue = minValue;
    this.normalizedMax = minValue;
    this.normalizedMin = maxValue;

}

void NeuralNetzzz::DataSet::addState(std::vector<float> inputs, type* expectedOutput, std::vector<Type*> rejectedOutputs)
{
    std::vector<float> normlizedInputStates;
    for(int inputIndex = inputs.begining(); i < inputs.size(); inputIndex++)
    {
        float normalizedValue = inputs[inputIndex] / (this.maxValue - this.minValue);
        if(normalizedValue < this.normalizedMin)
        {
            this.normalizedMin = normalizedValue;
        }
        if(normalizedValue > this.normalizedMax)
        {
            this.normalizedMax =  normalizedValue;
        }      
        normlizedInputStates.push_back(normalizedValue); 
    }
    this.inputs.push_back(normlizedInputStates);
    this.expectedOutputs.push_back(expectedOutput);
    this.rejectedOutputs.push_back(rejectedOutputs);
}

void NeuralNetzzz::DataSet::storeInJSON(string path)
{
    std::ifstream file(path,std::ifstream::binary);
    Json::Value jsonWriter;
    file >> jsonWriter;
    std::vector<std::vector<string>> jsonStringVector;
    for(int inputStateIndex=this.expectedOutputs.begining(); inputStateIndex<this.expectedOutputs.size(); inputStateIndex++)
    {
        jsonStringVector.push_back({"inputs": this.inputs[inputStateIndex],
                                    "expected_output": this.expectedOutputs[inputStateIndex],
                                    "rejected_outputs": this.rejectedOutputs[inputStateIndex],
                                    "num_inputs":this.inputs[inputStateIndex].size(),
                                    "num_states":this.expectedOutputs.size(),
                                    "max": this.normalizedMax,
                                    "min": this.normalizedMin});
        
    }
    jsonWriter << {"DataSet": jsonStringVector};
    file << jsonWriter;
}

void NeuralNetzzz::DataSet::JSONLoad(string path, int sizeOfSubset)
{
    std::ifstream file(path,std::ifstream::binary);
    Json::Value jsonReader;
    file >> jsonReader;
    for(auto inputStateindex=jsonReader["DataSet"].begining(); inputStateIndex < jsonReader["DataSet"].size(); inputStateIndex++)
    {
        std::vector<float> subset;
        std::vector<float> inputs = jsonReader["DataSet"][inputIndex]["inputs"];
        float average = 0.0;
        int count = 0;
        for(int inputIndex=inputs.begining(); inputIndex < inputs.size(); inputIndex++)
        {
            if((inputIndex % sizeOfSubset == 0 && inputIndex != 0) || sizeOfSubset == 1)
            {
                if(count != 0)
                {
                    subset.push_back(average/count);

                }
                else
                {
                    subset.push_back(inputs[inputIndex]);
                }
                count = 0;
                average = 0;
            }
            else
            {
                average += inputs[inputIndex];
                count += 1;
            }
        }
        Type expectedOutput = jsonReader["DataSet"][inputIndex]["expected_output"];
        std::vector<Type> rejectedOutputs = jsonReader["DataSet"][inputIndex]["rejected_outputs"];
        this.maxValue = jsonReader["DataSet"][inputIndex]["max"];
        this.minValue = jsonReader["DataSet"][inputIndex]["min"];
        this.addState(subset, expectedOutput, rejectedOutputs);
    }
}

void NeuralNetzzz::DataSet::deleteState(int index)
{
    std::vector<std::vector<float>> tempInputs;
    std::vector<Type> tempExpectedOutputs;
    std::vector<std::vector<Type>> tempRejectedOutputs;

}

void NeuralNetzzz::DataSet::replaceState(int index, std::vector<float> newInputs, type newExpected, std::vector<Type> newRejected)
{
    this.deleteState(index);
    this.addState(newInputs, newExpected, newRejected);
}

void NeuralNetzzz::DataSet::clear()
{
    this.inputs.clear();
    this.expectedOutputs.clear();
    this.rejectedOutputs.clear();
}

NeuralNetzzz::DataSet::~DataSet()
{
    
}
