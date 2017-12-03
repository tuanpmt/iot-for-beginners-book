# Sphinx and Travis Setup

This assumes that you're setting up a repository with only Sphinx (no code).  If you're not doing that, you'll need to modify some stuff here, using your best judgment.

1. First, you'll want to install Sphinx (`pip install sphinx`) and the Read the Docs theme (`pip install sphinx_rtd_theme`).
2. Then, go through `sphinx-quickstart`.  You shouldn't need most of the plugins, but enable anything you're interested in.
3. In `conf.py`, find the line `html_theme = 'alabaster'` and replace it with `html_theme = 'sphinx_rtd_theme'`.
4. Edit any Sphinx documentation files you're interested in, then do `make html` to check that everything runs.
5. Make sure to commit, and add `_build` to your `.gitignore`.
6. If you haven't already done so, set up the repository on GitHub, and push!
7. Go to [Travis](https://travis-ci.org), click the plus button, and flick the switch on your repository.
8. Now, add the above `.travis.yml` and `push.sh` files.  Make sure to make `push.sh` executable (`chmod u+x push.sh`).
9. Also, make sure to update `ORG`, `REPO`, and `EMAIL` in `.travis.yml`.
10. Go to GitHub, Settings, and then Personal Access Tokens.  Generate one that has push access to public repos (you can disable everything else).
11. Make sure you have Ruby and Gem installed.  Then, install the Travis gem - `gem install travis`.
12. In your repository root, do `travis encrypt GH_TOKEN=[paste your token here]`.
13. Put that result in your `.travis.yml` file, in the secure section I marked out.
14. Commit!  (Don't push yet)
15. Now, create a `gh-pages` branch and clear out your working directory (make sure nothing is uncommitted!).
    ```
    $ git checkout --orphan gh-pages
    $ rm -rf *
    ```
16. Add a `.nojekyll` file to instruct GitHub Pages not to use Jekyll.
     ```
    $ touch .nojekyll
    $ git commit -am "Initial gh-pages commit."
    ```
17. Send that up to GitHub with `git push -u origin gh-pages`.
18. Travis should start doing its thing.  Voila!