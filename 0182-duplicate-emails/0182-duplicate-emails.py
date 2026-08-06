import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    a=person.groupby(['email']).size()
    b=a[a>1].reset_index()[['email']]
    b=b.rename(columns={'email':'Email'})
    return b