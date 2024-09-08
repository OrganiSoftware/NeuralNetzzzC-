#ifndef LeakySquashedRELUActivationFunction
#define LeakySquashedRELUActivationFunction

namespace NeuralNetzzz
{
    class LeakySquashedRELUActivationFunction
    {   
        public:
            LeakySquashedRELUActivationFunction(float alpha, float maxActivation, float minActivation);
            float calculate(float x);
            float compDerivative(float weightedSum, float delCost);
            LeakySquashedRELUActivationFunction();
        private:
            float alpha;
            float maxActivation;
            float minActivation;
    };
}