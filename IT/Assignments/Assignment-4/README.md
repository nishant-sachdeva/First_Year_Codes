# N-Grams Smoothing
A revamped version of the N-Grams Smoothing Experiment hosted by IIIT-H for VLABS (a Govt. of India Initiative)

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

The following are required on your system in order to test the application

 1. Python
 2. Flask
 3. SQLAlchemy
 4. Linux System or Mac is preferred for testing
 5. flask_testing (subset of flask but has to be installed separately)

### Installation

1. Python

`    sudo apt-get update
`
`    sudo apt-get install python3.6
`
	Check the version of python using python3  -v. Python3.6 + is recommended.

2. Flask

`    pip install flask
`

If you face any difficulties with installation or setup, do raise an issue.

3. SQLAlchemy

`    pip install sqlalchemy
`

## Testing
For unit testing purposes, we have a file called test_pages.py which checks if all the url's are functional as per project requirements or not. This said file is present in the same directory as the run.py file.

-> For running the test file, run the following command:
	=> python3 test_pages.py
   This should test all the pages as to if they're running or not and report respective errors.



The setup for a flask application is pretty simple. Just run the following command:

python3 run.py

This should start a web server at localhost:5000/ Type this link into your broswer's URL field in order to view the application.

Note: Whenever changes are made, the flask application must be restarted for the web server to reflect the updated changes (unlsess the application is in debugger mode which then dosen't require a restart for every change) .

## Contributing

Visit /Contribute to view the general contribution guidelines. We openly welcome first time contributors but do ensure that you follow the guidelines mentioned strictly.

## Authors

 - **Manvith Reddy**
 - **Nishant Sachdeva**
