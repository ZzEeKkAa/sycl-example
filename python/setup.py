from skbuild import setup
from skbuild.platform_specifics import windows

# monkey patch compiler settings, so scikit build does not overwrite environment
windows._get_msvc_compiler_env = lambda version, toolset: windows.CachedEnv()

setup(
    name="hello-cpp",
    version="1.2.3",
    description="a minimal example package (cpp version)",
    author="The scikit-build team",
    license="MIT",
    packages=["hello"],
    python_requires=">=3.7",
)