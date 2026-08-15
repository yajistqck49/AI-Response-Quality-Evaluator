#include "evaluator.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>

int readScore(const std::string& name) {
    int score;
    while (true) {
        std::cout << name << " score (1-5): ";
        if (std::cin >> score && score >= 1 && score <= 5) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return score;
        }
        std::cout << "Please enter a whole number from 1 to 5.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string readComment(const std::string& name) {
    std::string comment;
    std::cout << name << " comment: ";
    std::getline(std::cin, comment);
    return comment;
}

int main() {
    std::cout << "AI Response Quality Evaluator\n";
    std::cout << "Simulates a human review workflow for an AI-generated response.\n\n";

    std::string response;
    std::cout << "Enter the AI-generated response to evaluate:\n> ";
    std::getline(std::cin, response);

    const std::vector<std::string> names = {
        "Relevance", "Accuracy", "Clarity", "Completeness", "Safety"
    };

    std::vector<Criterion> criteria;
    for (const auto& name : names) {
        int score = readScore(name);
        std::string comment = readComment(name);
        criteria.push_back({name, score, comment});
    }

    Evaluation evaluation = ResponseEvaluator::evaluate(response, criteria);
    ResponseEvaluator::printReport(evaluation);
    return 0;
}
