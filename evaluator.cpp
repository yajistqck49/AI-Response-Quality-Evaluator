#include "evaluator.h"
#include <iomanip>
#include <iostream>

Evaluation ResponseEvaluator::evaluate(const std::string& response,
                                       const std::vector<Criterion>& criteria) {
    Evaluation result{response, criteria, 0.0, "Not evaluated"};
    if (criteria.empty()) return result;

    double total = 0.0;
    for (const auto& criterion : criteria) total += criterion.score;

    result.overallScore = total / criteria.size();
    result.qualityBand = qualityBand(result.overallScore);
    return result;
}

std::string ResponseEvaluator::qualityBand(double score) {
    if (score >= 4.5) return "Excellent";
    if (score >= 3.5) return "Good";
    if (score >= 2.5) return "Needs Improvement";
    return "Poor";
}

void ResponseEvaluator::printReport(const Evaluation& evaluation) {
    std::cout << "\n=== AI RESPONSE QUALITY REPORT ===\n";
    std::cout << "Response: " << evaluation.response << "\n\n";

    for (const auto& criterion : evaluation.criteria) {
        std::cout << criterion.name << ": " << criterion.score << "/5\n";
        std::cout << "Comment: " << criterion.comment << "\n\n";
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Overall score: " << evaluation.overallScore << "/5\n";
    std::cout << "Quality band: " << evaluation.qualityBand << "\n";
}
