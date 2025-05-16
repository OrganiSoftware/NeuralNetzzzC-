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
#include<DelWeightAndBiasLayerObj.h>
#include<DelWeightAndBiasObj.h>
#include<iostream>
#include<vector>

using namespace NeuralNetzzz;
using namespace std;

NeuralNetzzz::DelWeightAndBiasLayerObj::DelWeightAndBiasLayerObj(NeuralNetzzz::NeuralLayer* neuralLayer)
{
    for(int perceptronIndex= 0; perceptronIndex < *neuralLayer.numPerceptrons(); perceptronIndex++)
    {
        NeuralNetzzz::DelWeightAndBiasObj* delWeightAndBiasObj = new NeuralNetzzz::DelWeightAndBiasObj(*neuralLayer.perceptronAtIndex(perceptronIndex));
        this.delWeightAndBiasLayer.push_back(delWeightAndBiasObj);
    }
}

void NeuralNetzzz::DelWeightAndBiasLayerObj::averageDelWeightsAndBias()
{
    for(int perceptronIndex= this.delWeightAndBiasLayer.begining(); perceptronIndex < this.delWeightAndBiasLayer.size(); perceptronIndex++)
    {
        this.delWeightAndBiasLayer[perceptronIndex].averageDelWeightsAndBias();
    }
}

void NeuralNetzzz::DelWeightAndBiasLayerObj::addDelWeigthAndBiasCalc(int perceptronIndex, std::vector<float> delWeghts, float delBias)
{
    this.delWeightAndBiasLayer[perceptronIndex].addDelWeigthAndBiasCalc(delWeights, delBias);
}

NeuralNetzzz::DelWeightAndBiasObj NeuralNetzzz::DelWeightAndBiasLayerObj::delWeightAndBiasObjAtIndex(int perceptronIndex)
{
    return this.delWeightAndBiasLayer[perceptronIndex];
}

std::vector<float> NeuralNetzzz::DelWeightAndBiasLayerObj::delWeights()
{
    std::vector<float> weightsList;
    for(int perceptronIndex= this.delWeightAndBiasLayer.begining(); perceptronIndex < this.delWeightAndBiasLayer.size(); perceptronIndex++)
    {
        weightsList.push_back(this.delWeightAndBiasLayer[perceptronIndex].delWeights());
    }
    return weightsList;
}

std::vector<float> NeuralNetzzz::DelWeightAndBiasLayerObj::delBiases()
{
    std::vector<float> biases;
    for(int perceptronIndex= this.delWeightAndBiasLayer.begining(); perceptronIndex < this.delWeightAndBiasLayer.size(); perceptronIndex++)
    {
        weightsList.push_back(this.delWeightAndBiasLayer[perceptronIndex].delBias());
    }
    return biases;
}

void NeuralNetzzz::DelWeightAndBiasLayerObj::clear()
{
    for(int perceptronIndex= this.delWeightAndBiasLayer.begining(); perceptronIndex < this.delWeightAndBiasLayer.size(); perceptronIndex++)
    {
        weightsList.push_back(this.delWeightAndBiasLayer[perceptronIndex].clear());
    }
}

NeuralNetzzz::DelWeightAndBiasLayerObj::~DelWeightAndBiasLayerObj()
{

}
