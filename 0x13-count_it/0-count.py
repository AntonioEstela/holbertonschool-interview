#!/usr/bin/python3
"""
recursive function that queries the Reddit API,
parses the title of all hot articles,
and prints a sorted count of given keywords
"""
import requests


def count_words(subreddit, word_list, after='', dict={}):
    """
    Recursive function
    """
    url = 'https://www.reddit.com/r/{}/hot.json?after={}'
    r = requests.get(url.format(subreddit, after),
                      headers={'User-Agent': 'custom'},
                      allow_redirects=False)

    if r and r.status_code == 200:
        list_req = r.json().get('data').get('children')

        for children in list_req:
            title = children.get('data').get('title')

            for word in word_list:
                try:
                    dict[word] += title.lower().split().count(word.lower())

                except KeyError:
                    dict[word] = title.lower().split().count(word.lower())

        after = r.json().get('data').get('after')

        if (after is None):
            for key, val in sorted(dict.items(),
                                   key=lambda x: (-x[1], x[0])):
                if (val != 0):
                    print("{}: {}".format(key.lower(), val))

            return

        return count_words(subreddit, word_list, after, dict)

    else:
        return