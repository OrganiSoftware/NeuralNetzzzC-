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
#include<DelWeightAndBiasObj.h>
#include<iostream>
#include<vector>

using namespace NeuralNetzzz;
using namespace std;


NeuralNetzzz::DelWeightAndBiasObj::DelWeightAndBiasObj(Perceptron* perceptron)
{
    this.delBias = 0.0;
    this.numWeightCalcs = 0;
    this.averaged = false;
    for(int weightIndex= 0; weightIndex < *perceptron.numInputs(); weightIndex++)
    {
        this.delWeights.push_back(0.0);
    }
}

void NeuralNetzzz::DelWeightAndBiasObj::addDelWeigthAndBiasCalc(std::vector<float> delWeights, float delBias)
{
    if (delWeights.size() == this.delWeights.size())
    {    
        for(int weightIndex=0; weightIndex < this.delWeights.size(); weightIndex++)
        {
            this.delWeights[weightIndex] += delWeights[weightIndex];
        }
        this.delBias += delBias;
        this.numWeightCalcs += 1;
        this.averaged = false;
    }
}

void NeuralNetzzz::DelWeightAndBiasObj::averageDelWeightAndBias()
{
    for(int weightIndex=0; weightIndex < this.delWeights.size(); weightIndex++)
    {
        this.delWeights[weightIndex] /= this.numWeightCalcs;
    }
    this.delBias /= this.numWeightCalcs;
    this.averaged = true;
    this.numWeightCalcs = 1;
}

std::vector<float> NeuralNetzzz::DelWeightAndBiasObj::delWeights()
{
    if(this.averaged)
    {
        return this.delWeights;
    }
    return NULL;
}

void NeuralNetzzz::DelWeightAndBiasObj::clear()
{
    for(int weightIndex= 0; weightIndex < this.delWeights.size(); weightIndex++)
    {
        this.delWeights[weightIndex] = 0;
    }
    this.averaged = false;
    this.numWeightCalcs = 0;
}

float NeuralNetzzz::DelWeightAndBiasObj::delBias()
{
    if(this.averaged)
    {
        return this.delBias;
    }
    return NULL;
}

NeuralNetzzz::DelWeightAndBiasObj::~DelWeightAndBiasObj()
{

}
