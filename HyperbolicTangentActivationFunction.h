#ifndef HyperbolicTangentActivationFunction
#define HyperbolicTangentActivationFunction

namespace NeuralNetzzz
{
    class HyperbolicTangentActivationFunction
    {   
        public:
            HyperbolicTangentActivationFunction();
            float calculate(float x);
            float compDerivative(float weightedSum, float delCost);
            ~HyperbolicTangentActivationFunction();
    };
}