# AI Response Quality Evaluator

A small C++ command-line application that simulates a human evaluation workflow for AI-generated responses.

## Evaluation criteria
- Relevance
- Accuracy
- Clarity
- Completeness
- Safety

The program calculates an average score out of 5 and assigns a quality band.

## Why I built this
This project demonstrates skills relevant to AI training and evaluation workflows:
- structured review of AI-generated content
- consistent scoring against predefined criteria
- input validation
- basic quantitative analysis
- technical documentation
- C++ programming

This is a simulation of human evaluation, not an AI model itself.

## Requirements
- C++17-compatible compiler

## Compile
```bash
g++ -std=c++17 main.cpp evaluator.cpp -o evaluator
```

## Run
```bash
./evaluator
```

## Score bands
| Score | Quality |
|---:|---|
| 4.50–5.00 | Excellent |
| 3.50–4.49 | Good |
| 2.50–3.49 | Needs Improvement |
| 1.00–2.49 | Poor |

## Portfolio relevance
Suitable as a small portfolio demonstration for AI data annotation, response evaluation, quality review, and AI training support roles.

## Author
Yagboyaju Nuhammad
