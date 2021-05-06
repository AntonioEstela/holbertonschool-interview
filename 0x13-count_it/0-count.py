#!/usr/bin/python3
"""
recursive function that queries the Reddit API,
parses the title of all hot articles, and prints a sorted count of given keywords 
"""
import requests


def recursive_search(subreddit, word_list, dict, after=""):
    """
    Recursive function that parses the title of all hot articles,
    and prints a sorted count of given keywords
    """
    url = 'https://api.reddit.com/r/{}/hot?after={}'.format(subreddit, after)

    r = requests.get(
        url, headers={'User-agent': 'product'}, allow_redirects=False)

    if r.status_code != 200:
        return None

    if after is None:
        return dict

    actual = r.json().get('data').get('children')
    after = r.json().get('data').get('after')

    for post in actual:
        title = post.get('data').get('title').split()

        for word in set(word_list):
            word = word.lower()
            if word in [w.lower() for w in title]:
                if dict.get(word):
                    dict[word] += 1
                else:
                    dict[word] = 1

    recursive_search(subreddit, word_list, dict, after)

    return dict


def print_alphabetically(dict):
    """
    Function that prints alphabetically a dictionary
    """
    for k, v in sorted(dict.items(), key=lambda value: value[1], reverse=True):
        if v != 0:
            print('{}: {}'.format(k, v))


def count_words(subreddit, word_list):
    """
    Recursive function
    """
    results = recursive_search(subreddit, word_list, {})

    if results:
        print_alphabetically(results)
