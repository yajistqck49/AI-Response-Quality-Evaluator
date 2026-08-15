#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <string>
#include <vector>

struct Criterion {
    std::string name;
    int score;
    std::string comment;
};

struct Evaluation {
    std::string response;
    std::vector<Criterion> criteria;
    double overallScore;
    std::string qualityBand;
};

class ResponseEvaluator {
public:
    static Evaluation evaluate(const std::string& response,
                               const std::vector<Criterion>& criteria);
    static std::string qualityBand(double score);
    static void printReport(const Evaluation& evaluation);
};

#endif
