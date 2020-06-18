# csvtojson

## Overview

Askia technical test. The goal of this project is to convert csv file to json file.

## Rules
 
### Instructions

You have to parse a CSV file and output a JSON file with the same data.

*  Any unquoted field that can be a number in the CSV should be a number in the outputJSON.
*  There can be commas within a quoted field.
*  Double quotes can be inhibited by doubling them.
*  The software should have a “header” option, if specified then the first line of the csv is considered as the header line and the JSON output should contain objects with the appropriate corresponding key, if no “header” option is specified then there will be no header line in the csv and the JSON output should contain arrays.

### Example

Example CSV:
Year,Car,Model,Description
1997,Ford,E350"1997","Ford","E350"
1997,Ford,E350,"Super,
luxurious truck"
1997,Ford,E350,"Super,
""luxurious"" truck"

### Bonus

There can be embedded line breaks in a field within double quotes like this:

1997,Ford,E350,"Go get

one nowthey are going

fast"

## Usage

### Platforms

csvtojson platforms available :

* `Linux`
* `Windows`

### Requirements

##### Windows Requirements

* `CMake` At least v3.1
* Windows `command prompt`
* Microsoft `Visual C++ 2015`

##### Linux & MacOS Requirements

* GNU-compatible `CMake` and `Make` (at least v3.1).
* POSIX-standard `shell`.
* A `C++17`-standard-compliant compiler

### Build

#### Targets

| Target           | Description                  |
|------------------|------------------------------|
| `[Nothing]`      | Build the application.       |
| `clean`          | Clean all built targets.     |

#### How to build the application

* `mkdir build` _In the root project directory_
* `cd build`
* `cmake ..`
* `cmake --build .`

This will generate a application `csvtojson[.exe]` in `bin` directory from the root project directory.

## Usage

`csvtojson[.exe] <input_csv_file_path> <output_json_file_path> [--header]`

| Argument                | Mandatory | Description                                                                        |
|-------------------------|-----------|------------------------------------------------------------------------------------|
| `input_csv_file_path`   | Yes       | CSV file path to read and translate to json format.                                |
| `output_json_file_path` | Yes       | JSON file path use has output.                                                     |
| `--header`              | No        | Option to specify then the first line of the CSV file is considered as the header. |

## Example

From this `sample/askia_instruction.csv` file :

````csv
Year,Car,Model,Description
1997,Ford,E350"1997","Ford","E350"
1997,Ford,E350,"Super,
luxurious truck"
1997,Ford,E350,"Super,
""luxurious"" truck"
1997,Ford,E350,"Go get
one nowthey are going
fast"
````

`csvtojson[.exe] sample/askia_instruction.csv askia_instruction.json` will generate :

````json
[
	["Year", "Car", "Model", "Description"],
	[1997, "Ford", "E350\"1997\"", "Ford", "E350"],
	[1997, "Ford", "E350", "Super,\nluxurious truck"],
	[1997, "Ford", "E350", "Super,\n\"\"luxurious\"\" truck"],
	[1997, "Ford", "E350", "Go get\none nowthey are going\nfast"]
]
````

`csvtojson[.exe] sample/askia_instruction.csv askia_instruction.json --header` will generate :

````json
[
	{
			"Year": 1997,
			"Car": "Ford",
			"Model": "E350\"1997\"",
			"Description": "Ford"
	},
	{
			"Year": 1997,
			"Car": "Ford",
			"Model": "E350",
			"Description": "Super,\nluxurious truck"
	},
	{
			"Year": 1997,
			"Car": "Ford",
			"Model": "E350",
			"Description": "Super,\n\"\"luxurious\"\" truck"
	},
	{
			"Year": 1997,
			"Car": "Ford",
			"Model": "E350",
			"Description": "Go get\none nowthey are going\nfast"
	}
]
````
