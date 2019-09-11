# GODDESSSort

In its current form, all of your runs should be in separate folders (e.g. Run030, Run031, etc.) and should include a .ldf file from ORRUBA and the corresponding GRETINA files (Digest.dat, Global.dat, etc.).

Change config.json to your files include path, prefix and runs to unpack.

## Calibrations

### QQQ5(Down/Up)Calibrations.dat

In this configuration file, the columns are:

| Det | Ring | Intercept | Slope |
|:---:|:----:|:---------:|:-----:|

Rings 32-35 correspond to the back sides:

| Ring Number | Back Side Number |
|:-----------:|:----------------:|
|      32     |         0        |
|      33     |         1        |
|      34     |         2        |
|      35     |         3        |

### SuperX3(Down/Up)Calibrations.dat
In this configuration file, the columns are:

| Det Id | Strip | Back | Intercept | Slope |
|:------:|:-----:|:----:|:---------:|:-----:|