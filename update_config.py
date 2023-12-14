import sys
import json

def update_config(runs, option, path='./'):
    """ Updates json config file for the run numbers """

    file = open(path+'config.json','r')
    json_object = json.load(file)
    file.close()

    json_object['runs'] = runs
    
    if (option=="-ORRUBA"):
        json_object['unpackORRUBA'] = "true"
        json_object['unpackGRETINA'] = "false"
        
    elif (option=="-GRETINA"):
        json_object['unpackORRUBA'] = "false"
        json_object['unpackGRETINA'] = "true"
        
    elif (option=="-both"):
        json_object['unpackORRUBA'] = "true"
        json_object['unpackGRETINA'] = "true"

    file = open(path+'config.json','w')
    json.dump(json_object,file,indent=1)
    file.close()


    return 0

def main():
    """ Main program """
    
    runs = [] # List for runs
    n = len(sys.argv)
    
    option = sys.argv[-1]
    
    for i in range(1,n-1):
        runs.append(sys.argv[i])
        
    update_config(runs, option)
    
main()
