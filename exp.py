import os
from subprocess import check_output, STDOUT, CalledProcessError
import csv
import time

# bench_path = '/home/wangchenglin/branching_loops_modified'
# bench_path = '/home/wangchenglin//icra/WALi-OpenNWA/Examples/cprover/tests/frankenstein/HOLA'
# bench_path = '/home/wangchenglin/c2z3/benchmarks/pldi22/sv-comp'
# bench_path = '/home/wangchenglin/c2z3/benchmarks/literature'
bench_path = '/home/wangchenglin/function91'
tot = 0
success = 0
fails = 0
csv_file = open('stat.csv', 'w', newline='')
csv_writer = csv.writer(csv_file)
for prefix, _, files in os.walk(bench_path):
    for c_file in files:
        if not c_file.endswith('.c') or c_file == '3.c': continue
        # if not c_file == 'Mono1_1-1.c': continue
        print(c_file)
        tot += 1
        full_c_path = os.path.join(prefix, c_file)
        end = 0
        try:
            s = time.time()
            out = check_output(['python', 'verify.py', full_c_path], stderr=STDOUT, timeout=60).decode()
            # end = time.time()
        except CalledProcessError as e:
            out = e.output.decode()
        except:
            out = ''
        if 'Correct' in out or 'Wrong' in out:
            success += 1
            t = time.time() - s
            if 'Correct' in out:
                print('correct')
            else:
                print('wrong')
        else:
            fails += 1
            t = 'fail'
            print('fail')
        csv_writer.writerow([full_c_path, t])
        print('%d/%d' % (success, tot))
        print('*'*20)
        
print('%d/%d' % (success, tot))
csv_file.close()
