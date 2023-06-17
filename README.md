# PushSwap tester

## Installation

- Install [Python](https://www.python.org/)

- In your PushSwap project folder :
```
git clone https://github.com/abdelbenamara/PushSwap.git tests/
```

## Usage

```
python3 tests/test.py 3
```
```
python3 tests/test.py 5
```
```
python3 tests/test.py 100
```
```
python3 tests/test.py 500
```

## Options

- By default, the n numbers are >= 1 and <= n, but you can random numbers in all possible integers by uncommenting the line https://github.com/abdelbenamara/PushSwap/blob/cf04a8d6d57669872d73bad12ba14f74b96c3896/test.py#L11 and by commenting the line https://github.com/abdelbenamara/PushSwap/blob/cf04a8d6d57669872d73bad12ba14f74b96c3896/test.py#L12

- By default, for n > 5 numbers, 1000 cases are tested, but you can change that amount with this variable https://github.com/abdelbenamara/PushSwap/blob/cf04a8d6d57669872d73bad12ba14f74b96c3896/test.py#L33
