import os
from plantuml import PlantUML

def generate_uml_diagram(input_file, output_file):
    plantuml = PlantUML(url='http://www.plantuml.com/plantuml/img/')
    plantuml.processes_file(input_file, output_file)

if __name__ == "__main__":
    input_file = "uml_diagram.puml"
    output_file = "uml_diagram.jpg"
    generate_uml_diagram(input_file, output_file)
