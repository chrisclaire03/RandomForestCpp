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

## Test with iris dataset [source](https://gist.github.com/curran/a08a1080b88344b0c8a7)

features: sepal_length, sepal_width, petal_length, petal_width, species
target feature = species
command:

```
./rf datasets/iris.csv 4 20 10 5 4 50
```

## Test with diabetes dataset [soure](https://www.kaggle.com/datasets/mathchi/diabetes-data-set)

features : Pregnancies, Glucose, BloodPressure, SkinThickness, Insulin,BMI ,DiabetesPedigreeFunction, Age, Outcome
target feature = Outcome
command:

```
./rf datasets/diabetes.csv 8
```

Outputs results from created test set.