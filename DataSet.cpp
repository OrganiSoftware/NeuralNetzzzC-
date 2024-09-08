#include<DynamicArray.h>
#include<DataSet.h>
#include<iostream>
#include<vector>


DataSet(float maxValue, float minValue)
{
    this.maxValue = maxValue;
    this.minValue = minValue;
    this.normalizedMax = minValue;
    this.normalizedMin = maxValue;

}

void addState(vector<float> inputs, type expectedOutput, vector<Type> rejectedOutputs)
{
    vector<float> normlizedInputStates;
    for(auto inputIndex = inputs.begining(); i < inputs.size(); inputIndex++)
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

void storeInJSON(string path);
void JSONLoad(string path, int sizeOfSubset);
bool deleteState(int index);
bool replaceState(int index);
~DataSet();