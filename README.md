[![Build](https://github.com/chrisclaire03/RandomForestCpp/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/chrisclaire03/RandomForestCpp/actions/workflows/c-cpp.yml)
# RandomForestCpp

## To Compile

```
make
```

## Executable Use Format

```
./rf data.csv targetFeatureIndex
```

## Test with diabetes dataset [soure](https://www.kaggle.com/datasets/mathchi/diabetes-data-set)

features : Pregnancies, Glucose, BloodPressure, SkinThickness, Insulin,BMI ,DiabetesPedigreeFunction, Age, Outcome
target feature = Outcome
command:

```
./rf datasets/diabetes.csv 8
```

Outputs results from created test set.