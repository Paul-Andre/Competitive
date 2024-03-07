import io
import pandas as pd

def clean_csv(input_stream):
    """
    :param input_stream: (StringIO) An in-memory stream for text I/O containing CSV data
    :returns: (String) A string containing CSV data
    """
    df = pd.read_csv(input_stream)
    df = df.dropna()
    return df.to_csv(header=False, index=False)

input_stream = io.StringIO("Name,Surname\nJohn,\nAnn,Franklin")
result_csv = clean_csv(input_stream)

print(result_csv)
input_stream.close()
