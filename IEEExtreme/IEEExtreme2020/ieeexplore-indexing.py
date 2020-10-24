import sys
import xml.etree.ElementTree as ET
import collections



def tokenize(string):
    out = []
    outtoken = []
    in_tag = False
    for c in string:
        if c.isspace():
            if (len(outtoken) != 0):
                out.append("".join(outtoken))
                outtoken = []
        elif c == ">" and in_tag:
            outtoken.append(">")
            out.append("".join(outtoken))
            outtoken = []
            in_tag = False
        else:
            if (c == "<"):
                if (len(outtoken) != 0):
                    out.append("".join(outtoken))
                    outtoken = []
                in_tag = True
            outtoken.append(c)

    if (len(outtoken) != 0):
        out.append("".join(outtoken))
        outtoken = []

    return out

def normalize_token(token):
    return token.lower().replace(".", "").replace("!", "").replace("?",
            "").replace(",", "")

def count_in(tag_name, tokens):
    in_tag = False
    opent = "<" + tag_name + ">"
    closet = "</" + tag_name + ">"
    counts = collections.Counter()
    for t in tokens:
        if t == opent :
            in_tag = True
        elif t  == closet:
            in_tag = False
        elif in_tag and t[0] != "<":
            counts[t]+=1
    return counts




def isTag(t):
    return t[0] == "<"

stop_words = list(input().split(";"))
terms = list(input().split(";"))
tokens = tokenize(sys.stdin.read()) 
tokens = [normalize_token(t) for t in tokens]
tokens = [t for t in tokens if isTag(t) or len(t) >= 4]
tokens = [t for t in tokens if t not in stop_words]
print(tokens)

ac = count_in("abstract", tokens)
tc = count_in("title", tokens)
bc = count_in("body", tokens)

L = sum(ac.values()) + sum(tc.values()) + sum(bc.values())

scores = [(-(ac[term]*3 + tc[term]*5 + bc[term]), term) for term in terms]
scores.sort() 

seen_score = set()
for neg_score, term in (scores):
    score = -neg_score
    seen_score.add(score)
    if len(seen_score) > 3: break
    print(term + ": " + str(score/L*100))





